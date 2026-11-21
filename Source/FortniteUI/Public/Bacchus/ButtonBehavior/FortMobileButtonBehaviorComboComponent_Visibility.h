// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponent_Visibility.h"
#include "FortMobileButtonBehaviorComboComponent_Visibility.generated.h"

class UFortMobileButtonBehaviorComponent_Visibility;

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FQueriedResultVisibilityAssignment
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="QueriedResultVisibilityAssignment")
	ESlateVisibility VisibilityToAssign;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="QueriedResultVisibilityAssignment")
	TArray<TObjectPtr<UFortMobileButtonBehaviorComponent_Visibility>> QueriedVisibilityComponents;

};

UCLASS()
class UFortMobileButtonBehaviorComboComponent_Visibility : public UFortMobileButtonBehaviorComponent_Visibility
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Display")
	TArray<FQueriedResultVisibilityAssignment> VisibilityAssignementQueries;

};

