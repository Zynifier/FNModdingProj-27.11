// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponent_IconPicker.h"
#include "FortMobileButtonBehaviorComponent_ActionBindingIconPicker.generated.h"

class UPaperSprite;

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FActionBindingIconPicker
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="ActionBindingIconPicker")
	TArray<FName> ActionNames;

	UPROPERTY(EditDefaultsOnly, Category="ActionBindingIconPicker")
	TObjectPtr<UPaperSprite> Sprite;

};

UCLASS()
class UFortMobileButtonBehaviorComponent_ActionBindingIconPicker : public UFortMobileButtonBehaviorComponent_IconPicker
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Display")
	TArray<FActionBindingIconPicker> ActionBindingSpriteOverrides;

};

