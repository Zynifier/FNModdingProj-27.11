// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonPoolableWidgetInterface.h"
#include "CommonUserWidget.h"
#include "Styling/SlateBrush.h"
#include "STW/FortPerks.h"
#include "FortPerkWidget_NUI.generated.h"

class UFortTooltipContext;
class UFortTooltipLoadingWrapper;
enum class EFortItemTier : uint8;
enum class EFortSupportBonusType : uint8;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortPerkWidget_NUI : public UCommonUserWidget, public ICommonPoolableWidgetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Perk Widget")
	bool GetIcon(FSlateBrush& Brush) const;

	UFUNCTION(BlueprintPure, Category="Perk Widget")
	EFortItemTier GetPerkTier() const;

	UFUNCTION(BlueprintPure, Category="Perk Widget")
	int32 GetRequiredLevel() const;

	UFUNCTION(BlueprintPure, Category="Perk Widget")
	EFortSupportBonusType GetSupportBonusType() const;

	UFUNCTION(BlueprintCallable, Category="Perk Widget")
	UFortTooltipContext* GetTooltipContext();

	UFUNCTION(BlueprintPure, Category="Perk Widget")
	FText GetTooltipTitle() const;

	UFUNCTION(BlueprintPure, Category="Perk Widget")
	bool HasAbility() const;

	UFUNCTION(BlueprintPure, Category="Perk Widget")
	bool IsPerkEmpty() const;

	UFUNCTION(BlueprintPure, Category="Perk Widget")
	bool IsPerkHighlighted() const;

	UFUNCTION(BlueprintPure, Category="Perk Widget")
	bool IsPerkUnlocked() const;

	UFUNCTION(BlueprintPure, Category="Perk Widget")
	bool IsTierPerk() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Perk Widget")
	void OnCombinedTooltipDescriptionReady(const FText& Description);

	UFUNCTION(BlueprintImplementableEvent, Category="Perk Widget")
	void OnPerkUpdated();

	UFUNCTION(BlueprintImplementableEvent, Category="Perk Widget")
	void OnTooltipDescriptionReady(const TArray<FText>& DescriptionList);

	UFUNCTION(BlueprintCallable, Category="Perk Widget")
	void RequestCombinedTooltipDescription();

	UFUNCTION(BlueprintCallable, Category="Perk Widget")
	void RequestTooltipDescription();

	UFUNCTION(BlueprintCallable, Category="Perk Widget")
	void SetTooltipContext(const UFortTooltipContext* InTooltipContext);

	UPROPERTY(BlueprintReadWrite, Category="FortPerkWidget_NUI", meta=(ExposeOnSpawn="TRUE"))
	FFortUIPerk Perk;

protected:
	UFUNCTION()
	void HandleAbilityKitTooltipLoaded();

	UPROPERTY()
	TObjectPtr<UFortTooltipContext> CachedTooltipContext;

private:
	UPROPERTY(EditAnywhere, Category="Perk Widget")
	bool bShouldUseSummaryTooltip;

	UPROPERTY(Transient)
	TObjectPtr<UFortTooltipLoadingWrapper> CachedTooltipLoadingWrapper;

};

