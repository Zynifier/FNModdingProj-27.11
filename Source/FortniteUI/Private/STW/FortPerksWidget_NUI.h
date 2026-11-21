// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "STW/FortPerks.h"
#include "FortPerksWidget_NUI.generated.h"

class UCommonLoadGuard;
class UFortHero;
class UFortPerkTierWidget_NUI;
class UFortPerkWidget_NUI;
class UFortTooltipContext;
enum class EFortPerksWidgetState : uint8;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortPerksWidget_NUI : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="FortPerksWidget")
	void OnGeneratePerk(FFortUIPerk FortPerk, UFortPerkWidget_NUI* PerkWidget);

	UFUNCTION(BlueprintImplementableEvent, Category="FortPerksWidget")
	void OnGeneratePerkTier(FFortUIPerkTier FortPerkTier, UFortPerkTierWidget_NUI* PerkTierWidget);

	UFUNCTION(BlueprintImplementableEvent)
	void OnHeroChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStateChanged();

	UFUNCTION(BlueprintCallable, Category="FortPerksWidget")
	void ProcessActiveAbilityPerksAsync();

	UFUNCTION(BlueprintCallable, Category="FortPerksWidget")
	void ProcessPerks();

	UFUNCTION(BlueprintCallable, Category="FortPerksWidget")
	void ProcessPerkTiers();

	UFUNCTION(BlueprintCallable, Category="FortPerksWidget")
	void SetHero(UFortHero* InHero);

	UFUNCTION(BlueprintCallable, Category="FortPerksWidget")
	void SetState(EFortPerksWidgetState InState, UFortHero* InEvolutionOption = nullptr);

	UPROPERTY(BlueprintReadOnly, Category="FortPerksWidget_NUI", meta=(ExposeOnSpawn="TRUE"))
	TObjectPtr<UFortHero> Hero;

	UPROPERTY(BlueprintReadOnly, Category="FortPerksWidget_NUI", meta=(ExposeOnSpawn="TRUE"))
	EFortPerksWidgetState State;

	UPROPERTY(BlueprintReadOnly, Category="FortPerksWidget_NUI", meta=(ExposeOnSpawn="TRUE"))
	TObjectPtr<UFortHero> EvolutionOption;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPerksWidget_NUI")
	TSubclassOf<UFortPerkTierWidget_NUI> PerkTierWidgetType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPerksWidget_NUI")
	TSubclassOf<UFortPerkWidget_NUI> PerkWidgetType;

protected:
	UPROPERTY()
	TObjectPtr<UFortTooltipContext> TooltipContext;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPerksWidget", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonLoadGuard> PerksListLoadGuard;

};

