// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "CheckDismissableActivatableWidget.h"
#include "FortActivatablePanelLTM.generated.h"

class AFortGameplayMutator;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortActivatablePanelLTM : public UCommonActivatableWidget, public ICheckDismissableActivatableWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortActivatablePanelLTM")
	TSubclassOf<AFortGameplayMutator> MutatorClassToWaitFor;

	UPROPERTY(BlueprintReadOnly, Category="LTM")
	TObjectPtr<AFortGameplayMutator> Mutator;

};

