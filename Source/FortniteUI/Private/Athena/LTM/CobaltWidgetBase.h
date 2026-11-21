// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "CobaltWidgetBase.generated.h"

class AFortAthenaMutator_Cobalt;

UCLASS()
class UCobaltWidgetBase : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	int32 GetCurrentRoundNameIndex() const;

	UPROPERTY(BlueprintReadOnly, Category="CobaltWidgetBase")
	TObjectPtr<AFortAthenaMutator_Cobalt> CobaltMutator;

	UPROPERTY(EditDefaultsOnly, Category="CobaltWidgetBase")
	TArray<FText> RoundNames;

	UPROPERTY(EditDefaultsOnly, Category="CobaltWidgetBase")
	FText InvalidRoundText;

};

