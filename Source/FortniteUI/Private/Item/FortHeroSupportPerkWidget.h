// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STW/Heroes/FortHeroSpecialization.h"
#include "FortHeroSupportPerkWidget.generated.h"

class UCommonTextBlock;
class UFortHero;
class UFortMultiSizeImage;
enum class EFortSupportBonusType : uint8;
enum class EFortSupportPerkWidgetState : uint8;

UENUM(BlueprintType)
enum class EFortSupportPerkWidgetState : uint8
{
	Normal = 0,
	Upgrade = 1,
	Evolution = 2,
};

UCLASS(BlueprintType, Blueprintable)
class UFortHeroSupportPerkWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortHeroSupportPerkWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintPure, Category="Hero Support Perk Widget")
	bool IsHeroInSupportSlot() const;

	UFUNCTION(BlueprintPure, Category="Hero Support Perk Widget")
	bool IsPerkActive() const;

	UFUNCTION(BlueprintPure, Category="Hero Support Perk Widget")
	bool IsPerkEmpty() const;

	UFUNCTION(BlueprintPure, Category="Hero Support Perk Widget")
	bool IsPerkHighlighted() const;

	UFUNCTION(BlueprintPure, Category="Hero Support Perk Widget")
	bool IsPerkInCorrectSlot() const;

	UFUNCTION(BlueprintPure, Category="Hero Support Perk Widget")
	bool IsPerkUnlocked() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Hero Support Perk Widget")
	void OnHeroUpdated();

	UFUNCTION(BlueprintImplementableEvent, Category="Hero Support Perk Widge")
	void OnStateChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Hero Support Perk Widget")
	void OnSupportTypeUpdated();

	UFUNCTION(BlueprintCallable, Category="Hero Support Perk Widget")
	void SetHeroToRepresent(const UFortHero* InHeroToRepresent);

	UFUNCTION(BlueprintCallable, Category="Hero Support Perk Widget")
	void SetState(const EFortSupportPerkWidgetState InState);

	UFUNCTION(BlueprintCallable, Category="Hero Support Perk Widget")
	void SetSupportTypeToRepresent(const EFortSupportBonusType InSupportTypeToRepresent);

	UPROPERTY(BlueprintReadOnly, Category="Hero Support Perk Widget")
	TWeakObjectPtr<UFortHero> HeroToRepresent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Hero Support Perk Widget")
	EFortSupportBonusType SupportTypeToRepresent;

	UPROPERTY(BlueprintReadOnly, Category="Hero Support Perk Widget")
	EFortSupportPerkWidgetState SupportPerkWidgetState;

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="Hero Support Perk Widget", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UFortMultiSizeImage> PerkImage;

	UPROPERTY(BlueprintReadOnly, Export, Category="Hero Support Perk Widget", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UCommonTextBlock> NameText;

	UPROPERTY(BlueprintReadOnly, Export, Category="Hero Support Perk Widget", meta=(BindWidget, EditInline="true", OptionalWidget="TRUE"))
	TObjectPtr<UCommonTextBlock> DescriptionText;

};

