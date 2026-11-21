// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponent_IconPicker.h"
#include "FortMobileButtonBehaviorComboComponent_IconPicker.generated.h"

class UFortMobileButtonBehaviorComponent_IconPicker;
class UPaperSprite;

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FQueriedResultIconAssignment
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="QueriedResultIconAssignment")
	TObjectPtr<UPaperSprite> SpriteToUse;

	UPROPERTY(EditDefaultsOnly, Instanced, Category="QueriedResultIconAssignment")
	TArray<TObjectPtr<UFortMobileButtonBehaviorComponent_IconPicker>> QueriedIconComponents;

};

UCLASS()
class UFortMobileButtonBehaviorComboComponent_IconPicker : public UFortMobileButtonBehaviorComponent_IconPicker
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Display")
	TArray<FQueriedResultIconAssignment> IconAssignementQueries;

};

