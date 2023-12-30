#include <stdexcept>
#include "CountryFeature.h"

Region regionFromStr(std::string& region) {
    if (region == "South Asia") {
        return Region::SOUTH_ASIA;
    } else if (region == "Europe & Central Asia") {
        return Region::EUROPE_CENTRAL_ASIA;
    } else if (region == "Middle East & North Africa") {
        return Region::MIDDLE_EAST_NORT_AFRICA;
    } else if (region == "East Asia & Pacific") {
        return Region::EAST_ASIA_PACIFIC;
    } else if (region == "Sub-Saharan Africa") {
        return Region::SUB_SAHARAN_AFRICA;
    } else if (region == "Latin America & Caribbean") {
        return Region::LATIN_AMERICA_CARIBBEAN;
    } else if (region == "North America") {
        return Region::NORTH_AMERICA;
    } else {
        throw std::invalid_argument("Wrong region!");
    }
}

Income incomeFromStr(const std::string& incomeGroup) {
    if (incomeGroup == "Low income") {
        return LOW;
    } else if (incomeGroup == "Upper middle income") {
        return UPPER_MIDDLE;
    } else if (incomeGroup == "High income") {
        return HIGH;
    } else if (incomeGroup == "Lower middle income") {
        return LOWER_MIDDLE;
    } else {
        throw std::invalid_argument("Wrong income group!");
    }
}

CountryFeature::CountryFeature() {
    code = "AFG";
    region = Region::SOUTH_ASIA;
    income = LOW;
}
