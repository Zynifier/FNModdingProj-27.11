// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortAthenaSurvivorTierBadge.generated.h"

enum class EFortAthenaSurvivorTierBadgeSize : uint8;

UENUM(BlueprintType)
enum class EFortAthenaSurvivorTierBadgeSize : uint8
{
	Small = 0,
	Large = 1,
	Count = 2 UMETA(Hidden),
};

UCLASS()
class FORTNITEUI_API UFortAthenaSurvivorTierBadge : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortAthenaSurvivorTierBadge(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	void HandlePostMatchVisibility();

	UFUNCTION(BlueprintCallable)
	void OverrideTierAndPrestigeLevel(const int32 CustomTier, const int32 CustomPrestigeLvl);

	UFUNCTION(BlueprintCallable)
	void SetBadgeSize(const EFortAthenaSurvivorTierBadgeSize InBadgeSize);

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="SurvivorTierBadge", meta=(DisplayName="OnBadgeSizeChanged"))
	void BP_OnBadgeSizeChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="SurvivorTierBadge", meta=(DisplayName="OnPresentAnimation"))
	void BP_OnPresentAnimation(const int32 BeforeTier, const int32 BeforePrestigeLevel, const int32 AfterTier, const int32 AfterPrestigeLevel);

	UFUNCTION(BlueprintImplementableEvent, Category="SurvivorTierBadge", meta=(DisplayName="OnSurvivorTierStateChanged"))
	void BP_OnSurvivorTierStateChanged(const int32 Tier, const int32 PrestigeLevel);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaSurvivorTierBadge", meta=(AllowPrivateAccess))
	EFortAthenaSurvivorTierBadgeSize BadgeSize;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortAthenaSurvivorTierBadge")
	int32 EditorPreviewTier;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortAthenaSurvivorTierBadge")
	int32 EditorPreviewPrestigeLevel;
#endif

};

