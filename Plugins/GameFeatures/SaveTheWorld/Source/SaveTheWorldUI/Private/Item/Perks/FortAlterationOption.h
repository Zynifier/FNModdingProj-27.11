// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonPoolableWidgetInterface.h"
#include "CommonButtonLegacy.h"
#include "FortItemQuantityPair.h"
#include "STW/Items/FortAlterableItem.h"
#include "FortAlterationOption.generated.h"

class UFortAlterationItemDefinition;
enum class EFortAlterationOptionType : uint8;

UENUM(BlueprintType)
enum class EFortAlterationOptionType : uint8
{
	Upgrade = 0,
	Replacement = 1,
	Max_NONE = 2 UMETA(Hidden),
};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortAlterationOption : public UCommonButtonLegacy, public ICommonPoolableWidgetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="FortAlterationOption")
	UFortAlterationItemDefinition* GetAlterationDefinition() const;

	UFUNCTION(BlueprintPure, Category="FortAlterationOption")
	EFortAlterationOptionType GetAlterationOptionType() const;

	UFUNCTION(BlueprintPure, Category="FortAlterationOption")
	float GetCurrentPipCount(float MaxPipCount) const;

	UFUNCTION(BlueprintPure, Category="FortAlterationOption")
	float GetNextPipCount(float MaxPipCount) const;

	UFUNCTION(BlueprintPure, Category="FortAlterationOption")
	TArray<FFortItemQuantityPair> GetRequiredIngredients() const;

	UFUNCTION(BlueprintImplementableEvent, Category="FortAlterationOption")
	void OnSetup();

	UFUNCTION(BlueprintCallable, Category="FortAlterationOption")
	void Setup(FAlterationOption& InAlterationOption, EFortAlterationOptionType InAlterationOptionType);

private:
	UPROPERTY()
	FAlterationOption AlterationOption;

};

