#pragma once
#include "Column.h"
#include "Series.h"

class RealChart : public Column, public Series {
public:
    RealChart(int aLiczbaPunktow, const std::string& aNazwa, const std::string& aSeriesNazwa, TypWykresu aTyp);
    RealChart();
    ~RealChart();
    std::string getChartName() const;
    std::string getSeriesName() const;
    friend std::ostream& operator<<(std::ostream& os, const RealChart& rc);
};
