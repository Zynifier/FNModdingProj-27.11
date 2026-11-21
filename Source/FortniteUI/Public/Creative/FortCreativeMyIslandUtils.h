// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Creative/FortCreativeTypes.h"
#include "FortCreativeMyIslandUtils.generated.h"

class APlayerController;

UCLASS(NotBlueprintable)
class UFortCreativeMyIslandUtils : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static bool CanOptInForDeviceUpgrades(const APlayerController* PlayerController);

	UFUNCTION(BlueprintPure)
	static bool CanPublish(const APlayerController* PlayerController);

	UFUNCTION(BlueprintPure)
	static bool CanUpdateIslandThumbnail(const APlayerController* PlayerController);

	UFUNCTION(BlueprintPure)
	static FString GetCreatorPortalQrImageUrl();

	UFUNCTION(BlueprintPure)
	static int32 GetMaximumDescriptionLength();

	UFUNCTION(BlueprintPure)
	static int32 GetMaximumDescriptionTagLength();

	UFUNCTION(BlueprintPure)
	static int32 GetMaximumIntroductionLength();

	UFUNCTION(BlueprintPure)
	static int32 GetMaximumLocaleLength();

	UFUNCTION(BlueprintPure)
	static int32 GetMaximumTitleLength();

	UFUNCTION(BlueprintPure)
	static int32 GetMinimumTitleLength();

	UFUNCTION(BlueprintPure)
	static const FText& GetMyIslandDisplayName();

	UFUNCTION(BlueprintPure)
	static FName GetMyIslandTabID();

	UFUNCTION(BlueprintPure)
	static float GetStringSearchDelay();

	UFUNCTION(BlueprintPure)
	static int32 GetStringSearchMinCharacters();

	UFUNCTION(BlueprintPure)
	static bool HasCreatorRefreshPermission(const APlayerController* PlayerController);

	UFUNCTION(BlueprintPure)
	static bool HasUpgradedDevices(const APlayerController* PlayerController);

	UFUNCTION(BlueprintPure)
	static bool IsIslandIntroductionValid(int32& OutIntroductionLength, int32& OutMaxIntroductionLength, const FCreativeIslandInfo& IslandInfo);

	UFUNCTION(BlueprintPure)
	static bool IsIslandTitleValid(int32& OutTitleLength, int32& OutMinTitleLength, int32& OutMaxTitleLength, const FCreativeIslandInfo& IslandInfo);

	UFUNCTION(BlueprintPure)
	static bool IsPublishFAQEnabled();

	UFUNCTION(BlueprintPure)
	static bool IsUserLocaleValid(int32& OutUserLocaleLength, int32& OutMaxUserLocaleLength, const FCreativeIslandInfo& IslandInfo);

	UFUNCTION(BlueprintCallable)
	static void OptInForDeviceUpgrades(APlayerController* PlayerController);

	UFUNCTION(BlueprintPure)
	static bool ShouldAddTabsToMapScreen(const APlayerController* PlayerController);

	UFUNCTION(BlueprintPure)
	static bool ShouldHideDefaultCreativeTab(const APlayerController* PlayerController);

	UFUNCTION(BlueprintPure)
	static bool ShouldHideDefaultMyIslandTab(const APlayerController* PlayerController);

	UFUNCTION(BlueprintPure)
	static bool ShouldHideIslandSettingsTab();

	UFUNCTION(BlueprintPure)
	static bool ShouldUseLegacyPublishUI();

};

