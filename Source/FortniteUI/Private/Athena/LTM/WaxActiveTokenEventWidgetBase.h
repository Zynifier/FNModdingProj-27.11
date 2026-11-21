// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "WaxActiveTokenEventWidgetBase.generated.h"

class AFortAthenaMutator_Wax;

UCLASS()
class UWaxActiveTokenEventWidgetBase : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="WaxActiveTokenEventWidgetBase")
	TObjectPtr<AFortAthenaMutator_Wax> WaxMutator;

	UPROPERTY(BlueprintGetter=GetWaxTokensMediumCrit, Category="WaxActiveTokenEventWidgetBase")
	int32 WaxTokensForMediumCrit;

	UPROPERTY(BlueprintGetter=GetWaxTokensHighCrit, Category="WaxActiveTokenEventWidgetBase")
	int32 WaxTokensForHighCrit;

private:
	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	int32 GetWaxTokensHighCrit() const;

	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	int32 GetWaxTokensMediumCrit() const;

};

