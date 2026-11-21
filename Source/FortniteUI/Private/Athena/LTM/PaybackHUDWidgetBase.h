// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "PaybackHUDWidgetBase.generated.h"

class AFortAthenaMutator_Payback;
class AFortGameplayMutator;

UCLASS()
class UPaybackHUDWidgetBase : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	virtual void OnMutatorAvailable(AFortGameplayMutator* MutatorActor);

	UPROPERTY(BlueprintReadOnly, Category="PaybackHUDWidgetBase")
	TObjectPtr<AFortAthenaMutator_Payback> CachedPaybackMutator;

};

