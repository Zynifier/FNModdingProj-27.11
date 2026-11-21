// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "FortHeroLoadoutSlotButton.generated.h"

class UFortHeroLoadoutSlotButton;
class UMenuAnchor;

UENUM(BlueprintType)
enum class EHeroLoadoutSlotType : uint8
{
	/*
*	
*/
	CommanderSlot = 0,
	/*
*	
*/
	TeamPerkSlot = 1,
	/*
*	
*/
	CrewSlot = 2,
	/*
*	
*/
	GadgetSlot = 3,
};

UCLASS(BlueprintType, Blueprintable)
class UFortHeroLoadoutSlotButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMenuOpenChangedEvent, UFortHeroLoadoutSlotButton*, SlotButton, bool, bIsMenuOpen);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRequestChangeHero, UFortHeroLoadoutSlotButton*, SlotButton);

public:
	UFUNCTION(BlueprintPure)
	bool IsContextMenuOpen() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHeroLoadoutSlotButton")
	FName SlotName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHeroLoadoutSlotButton")
	int32 SlotIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHeroLoadoutSlotButton")
	EHeroLoadoutSlotType SlotType;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnRequestChangeHero OnRequestChangeHero;

	UPROPERTY(BlueprintAssignable)
	FOnMenuOpenChangedEvent OnContextMenuOpenChanged;

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortHeroLoadoutSlotButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UMenuAnchor> ContextMenuAnchor;

private:
	UFUNCTION()
	void HandleMenuOpenChanged(bool bIsMenuOpen);

};

