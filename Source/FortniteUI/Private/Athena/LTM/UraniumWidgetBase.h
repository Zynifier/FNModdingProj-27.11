// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "UraniumWidgetBase.generated.h"

class AFortAthenaMutator_Uranium;

UCLASS()
class UUraniumWidgetBase : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="UraniumWidgetBase")
	TObjectPtr<AFortAthenaMutator_Uranium> UraniumMutator;

};

