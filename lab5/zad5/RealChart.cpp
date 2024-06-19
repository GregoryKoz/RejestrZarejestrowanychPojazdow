#include "RealChart.h"

RealChart::RealChart(int aLiczbaPunktow, const std::string& aNazwa, const std::string& aSeriesNazwa, TypWykresu aTyp)
    : Column(aNazwa, aLiczbaPunktow, aTyp), Series(aLiczbaPunktow, aSeriesNazwa) {
    std::cout << "Konstruktor RealChart\n";
}

RealChart::RealChart()
    : RealChart(0, "Default Chart", "Default Series", TypWykresu::Column) {
    std::cout << "Konstruktor domyœlny RealChart\n";
}

RealChart::~RealChart() {
    std::cout << "Destruktor RealChart\n";
}

std::string RealChart::getChartName() const {
    return Column::objectName;
}

std::string RealChart::getSeriesName() const {
    return Series::objectName;
}

std::ostream& operator<<(std::ostream& os, const RealChart& rc) {
    os << "Chart Name: " << rc.getChartName() << ", Series Name: " << rc.getSeriesName();
    return os;
}
