// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortMobileButtonBehaviorComponent.generated.h"

class UFortButtonBehaviorComponentOverride;
class UFortMobileActionButtonBehavior;

UCLASS(Abstract, DefaultToInstanced, EditInlineNew)
class FORTNITEUI_API UFortMobileButtonBehaviorComponent : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<UFortMobileActionButtonBehavior> ButtonBehavior;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<UFortButtonBehaviorComponentOverride*> ButtonBehaviorComponentOverrides;

};

