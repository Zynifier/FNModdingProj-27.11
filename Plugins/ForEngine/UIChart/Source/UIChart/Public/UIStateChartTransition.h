// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UIStateChartTransition.generated.h"

class UUIState;

UCLASS()
class UICHART_API UUIStateChartTransition : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUIState> Source;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUIState> Target;

};

