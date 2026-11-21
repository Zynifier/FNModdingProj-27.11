// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponent_Visibility.h"
#include "FortMobileButtonBehaviorComponent_ActionBindingVisibility.generated.h"

UENUM(BlueprintType)
enum class EActionBindingComparisonType : uint8
{
	NoneBound = 0,
	AnyBound = 1,
	AllBound = 2,
};

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FActionBindingVisibility
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="ActionBindingVisibility")
	TArray<FName> ActionNames;

	UPROPERTY(EditDefaultsOnly, Category="ActionBindingVisibility")
	EActionBindingComparisonType ComparisonType;

	UPROPERTY(EditDefaultsOnly, Category="ActionBindingVisibility")
	ESlateVisibility Visibility;

};

UCLASS()
class UFortMobileButtonBehaviorComponent_ActionBindingVisibility : public UFortMobileButtonBehaviorComponent_Visibility
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortMobileButtonBehaviorComponent_ActionBindingVisibility")
	TArray<FActionBindingVisibility> ActionBindingVisibilites;

};

