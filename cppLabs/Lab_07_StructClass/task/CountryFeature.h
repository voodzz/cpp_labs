#pragma once
#include <map>
#include <string>
#include <vector>


enum class Region {
    SOUTH_ASIA, // South Asia
    EUROPE_CENTRAL_ASIA, // Europe & Central Asia
    MIDDLE_EAST_NORT_AFRICA, // Middle East & North Africa
    EAST_ASIA_PACIFIC, // East Asia & Pacific
    SUB_SAHARAN_AFRICA, // Sub-Saharan Africa
    LATIN_AMERICA_CARIBBEAN, // Latin America & Caribbean
    NORTH_AMERICA, // North America
};

Region regionFromStr(std::string&);

enum Income {
    LOW, // Low income
    UPPER_MIDDLE, // Upper middle income
    HIGH, // High income
    LOWER_MIDDLE // Lower middle income
};

Income incomeFromStr(const std::string&);

class CountryFeature {
public:
    CountryFeature();
    std::string code; // country_code
    Region region; // region of location
    Income income;
};
