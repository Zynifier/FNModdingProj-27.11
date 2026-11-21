// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "CreativeLowMemoryFallbackSettings.generated.h"

class UFortPlaylist;
class UObject;

USTRUCT()
struct FCreativeLowMemoryFallbackFreeMemoryThresholds
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="CreativeLowMemoryFallbackFreeMemoryThresholds")
	float FallbackMB;

	UPROPERTY(EditDefaultsOnly, Category="CreativeLowMemoryFallbackFreeMemoryThresholds")
	float WarningMB;

	UPROPERTY(EditDefaultsOnly, Category="CreativeLowMemoryFallbackFreeMemoryThresholds")
	float RecoveryMB;

};

USTRUCT()
struct FCreativeLowMemoryFallbackUserFacingText
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="CreativeLowMemoryFallbackUserFacingText", meta=(MultiLine="TRUE"))
	FText ExitToMainMenuReasonText;

	UPROPERTY(EditAnywhere, Category="CreativeLowMemoryFallbackUserFacingText", meta=(MultiLine="TRUE"))
	FText WarningToastTitle;

	UPROPERTY(EditAnywhere, Category="CreativeLowMemoryFallbackUserFacingText", meta=(MultiLine="TRUE"))
	FText WarningToastDescription;

};

UCLASS(Config=Game, DefaultConfig)
class UCreativeLowMemoryFallbackSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="CreativeLowMemoryFallbackSettings")
	TSoftObjectPtr<UObject> WarningToastIcon;

private:
	UPROPERTY(EditAnywhere, Config, Category="CreativeLowMemoryFallbackSettings")
	FCreativeLowMemoryFallbackUserFacingText DefaultText;

	UPROPERTY(EditDefaultsOnly, Config, Category="CreativeLowMemoryFallbackSettings")
	TMap<TSoftObjectPtr<UFortPlaylist>, FCreativeLowMemoryFallbackFreeMemoryThresholds> PlaylistOverrideThresholds;

	UPROPERTY(EditDefaultsOnly, Config, Category="CreativeLowMemoryFallbackSettings")
	TMap<TSoftObjectPtr<UFortPlaylist>, FCreativeLowMemoryFallbackUserFacingText> PlaylistOverrideText;

};

