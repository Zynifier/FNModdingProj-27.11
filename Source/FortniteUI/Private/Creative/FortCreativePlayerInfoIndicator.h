// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortActorIndicatorWidget.h"
#include "Minigame/FortMinigameTypes.h"
#include "FortCreativePlayerInfoIndicator.generated.h"

class AFortMinigame;
class AFortPlayerState;
class AFortPlayerStateAthena;
class AFortVolume;
class APlayerState;
class UImage;
enum class EFortMinigameState : uint8;
enum class EPlayerIndicatorDisplayMode : uint8;

UCLASS(BlueprintType, Blueprintable)
class UFortCreativePlayerInfoIndicator : public UFortActorIndicatorWidget
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleHitPointsChanged(AFortPlayerState* PlayerState, float Health, float HealthMax, float Shield, float ShieldMax);

	UFUNCTION()
	void HandleIndicatorRulesChanged(EPlayerIndicatorDisplayMode DisplayMode);

	UFUNCTION()
	void HandleMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState MinigameState);

	UFUNCTION()
	void HandlePlayerEnteredVolume(APlayerState* Client, AFortVolume* Volume);

	UFUNCTION()
	void HandlePlayerExitedVolume(APlayerState* Client, AFortVolume* Volume);

	UPROPERTY(EditDefaultsOnly, Category="FortCreativePlayerInfoIndicator", meta=(AllowPrivateAccess="true"))
	FVector RelativeLocationWhileDBNO;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativePlayerInfoIndicator", meta=(AllowPrivateAccess="true"))
	FVector RelativeLocationWhileAlive;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativePlayerInfoIndicator", meta=(AllowPrivateAccess="true"))
	FVector2D ScreenSpaceOffsetToScale;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativePlayerInfoIndicator", meta=(AllowPrivateAccess="true"))
	TArray<EFortMinigameState> ValidMinigameTypesToShowIndicator;

	UPROPERTY(EditDefaultsOnly, Category="FortCreativePlayerInfoIndicator", meta=(AllowPrivateAccess="true"))
	bool bKeepTargetUntilNewValidTarget;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePlayerInfoIndicator", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_HealthBar;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePlayerInfoIndicator", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_ShieldBar;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePlayerInfoIndicator", meta=(AllowPrivateAccess="true", BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_DBNOBar;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerStateAthena> TrackedPlayerState;

};

