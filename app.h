//! @file courcework/app.h
//! @author Лещинскас Э.Э.
//! @note Ответственный: Полевой Д.В.
//! @brief Заголовочный файл, который реализует логику приложения

#define _USE_MATH_DEFINES

#include <imgui/imgui.h>

#include <string>
#include <vector>
#include <utility>
#include <math.h>
#include <iostream>

class App
{
public:
    App()
    {
    }
    ~App()
    {
    }

    struct Point {
        float x;
        float y;
        float z;
    };

    //!@brief Функция, которая расчитывает координаты точек
    //  @param[in] radius - Радиус шара
    //  @param[in] numPoints - Количество точек на шаре
    //  @param[in] rotationAngle - Угол поворота шара
    std::vector<Point> calculatePointsOnSphere(int radius, int numPoints, int rotationAngle) {
        std::vector<Point> result;

        double goldenAngle = M_PI * (3.0 - std::sqrt(5.0));  // Угол золотого сечения

        for (int i = 0; i < numPoints; i++) {
            float y = 1 - (i / static_cast<double>(numPoints - 1)) * 2;  // Диапазон [-1, 1]
            float radiusOfSlice = std::sqrt(1 - y * y);  // Радиус окружности для текущего y

            float theta = goldenAngle * i + rotationAngle;  // Угол для текущей точки

            float x = std::cos(theta) * radiusOfSlice;
            float z = std::sin(theta) * radiusOfSlice;

            Point point { x * radius, y * radius, z * radius };
            result.push_back(point);
        }

        return result;
    }

    //!@brief Функция, которая реализует интерфейс приложения
    //  @param[in] w - Ширина окна
    // @param[in] h - Высота окна
    void display(int w, int h)
    {
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImVec2(w, h));
        ImGui::Begin("Example", nullptr, ImGuiWindowFlags_::ImGuiWindowFlags_NoMove
                                         | ImGuiWindowFlags_::ImGuiWindowFlags_NoCollapse
                                         | ImGuiWindowFlags_::ImGuiWindowFlags_NoResize
                                         | ImGuiWindowFlags_::ImGuiWindowFlags_NoTitleBar);


        ImGui::InputInt("Num points", &numPoints_);
        ImGui::InputInt("Radius", &radius_);
        if ( ImGui::SliderInt("Angle", &angle_, 0, 360) )
        {
            result = calculatePointsOnSphere(radius_, numPoints_, angle_);
        }

        if ( ImGui::Button("Show") )
        {
            result = calculatePointsOnSphere(radius_, numPoints_, angle_);

            for (auto point : result)
            {
                std::cout<<"Point => "<<point.x<<" -- " <<point.y <<" -- " <<point.z<<std::endl;
            }
        }


        ImDrawList* draw_list = ImGui::GetWindowDrawList();
        ImVec2 center = ImGui::GetCursorScreenPos();

        center.x += 100 + radius_;
        center.y += (radius_ + 10);

        draw_list->AddCircle(center, radius_, ImColor(150,150,150));

        for ( int i = 0; i < result.size(); i += 1 )
        {
            draw_list->AddCircle({result[i].x + center.x, result[i].y + center.y}, 1, ImColor(255,255,255));
//            std::cout<<"Point "<<i+1<<" => "<< result[i].x << "  " << result[i].y<<std::endl;
        }

        ImGui::End();
    }


private:

    int numPoints_ = 0; //!< Количество точек на поверхности шара
    int radius_ = 0; //!< Радиус шара
    int angle_ = 0; //!< Угол поворота шара

    char nameString_[2048] = "";

    std::vector<std::pair<int, int> > points_{};
    std::vector<Point> result; //!< Список координат точек
};