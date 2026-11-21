// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/FortCreativeMyIslandUtils.h"

bool UFortCreativeMyIslandUtils::CanOptInForDeviceUpgrades(const APlayerController* PlayerController)
{
	return false;
}

bool UFortCreativeMyIslandUtils::CanPublish(const APlayerController* PlayerController)
{
	return false;
}

bool UFortCreativeMyIslandUtils::CanUpdateIslandThumbnail(const APlayerController* PlayerController)
{
	return false;
}

FString UFortCreativeMyIslandUtils::GetCreatorPortalQrImageUrl()
{
	return FString();
}

int32 UFortCreativeMyIslandUtils::GetMaximumDescriptionLength()
{
	return int32();
}

int32 UFortCreativeMyIslandUtils::GetMaximumDescriptionTagLength()
{
	return int32();
}

int32 UFortCreativeMyIslandUtils::GetMaximumIntroductionLength()
{
	return int32();
}

int32 UFortCreativeMyIslandUtils::GetMaximumLocaleLength()
{
	return int32();
}

int32 UFortCreativeMyIslandUtils::GetMaximumTitleLength()
{
	return int32();
}

int32 UFortCreativeMyIslandUtils::GetMinimumTitleLength()
{
	return int32();
}

const FText& UFortCreativeMyIslandUtils::GetMyIslandDisplayName()
{
	static FText Dummy;
	return Dummy;
}

FName UFortCreativeMyIslandUtils::GetMyIslandTabID()
{
	return FName();
}

float UFortCreativeMyIslandUtils::GetStringSearchDelay()
{
	return float();
}

int32 UFortCreativeMyIslandUtils::GetStringSearchMinCharacters()
{
	return int32();
}

bool UFortCreativeMyIslandUtils::HasCreatorRefreshPermission(const APlayerController* PlayerController)
{
	return false;
}

bool UFortCreativeMyIslandUtils::HasUpgradedDevices(const APlayerController* PlayerController)
{
	return false;
}

bool UFortCreativeMyIslandUtils::IsIslandIntroductionValid(int32& OutIntroductionLength, int32& OutMaxIntroductionLength, const FCreativeIslandInfo& IslandInfo)
{
	return false;
}

bool UFortCreativeMyIslandUtils::IsIslandTitleValid(int32& OutTitleLength, int32& OutMinTitleLength, int32& OutMaxTitleLength, const FCreativeIslandInfo& IslandInfo)
{
	return false;
}

bool UFortCreativeMyIslandUtils::IsPublishFAQEnabled()
{
	return false;
}

bool UFortCreativeMyIslandUtils::IsUserLocaleValid(int32& OutUserLocaleLength, int32& OutMaxUserLocaleLength, const FCreativeIslandInfo& IslandInfo)
{
	return false;
}

void UFortCreativeMyIslandUtils::OptInForDeviceUpgrades(APlayerController* PlayerController)
{
}

bool UFortCreativeMyIslandUtils::ShouldAddTabsToMapScreen(const APlayerController* PlayerController)
{
	return false;
}

bool UFortCreativeMyIslandUtils::ShouldHideDefaultCreativeTab(const APlayerController* PlayerController)
{
	return false;
}

bool UFortCreativeMyIslandUtils::ShouldHideDefaultMyIslandTab(const APlayerController* PlayerController)
{
	return false;
}

bool UFortCreativeMyIslandUtils::ShouldHideIslandSettingsTab()
{
	return false;
}

bool UFortCreativeMyIslandUtils::ShouldUseLegacyPublishUI()
{
	return false;
}
