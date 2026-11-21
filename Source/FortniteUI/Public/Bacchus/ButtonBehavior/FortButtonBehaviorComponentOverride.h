// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Bacchus/ButtonBehavior/FortMobileButtonBehaviorComponentTypes.h"
#include "FortButtonBehaviorComponentOverride.generated.h"

class UFortMobileButtonBehaviorComponent;

UCLASS(Abstract, DefaultToInstanced, EditInlineNew)
class FORTNITEUI_API UFortButtonBehaviorComponentOverride : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortButtonBehaviorComponentOverride")
	TSubclassOf<UFortMobileButtonBehaviorComponent> TargetComponentToFilter;

	UPROPERTY(EditDefaultsOnly, Category="FortButtonBehaviorComponentOverride")
	FTagFilterOverride TagFilterOverride;

};

