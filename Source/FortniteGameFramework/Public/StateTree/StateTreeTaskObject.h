// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/StateTreeTaskBlueprintBase.h"
#include "StateTreeTaskObject.generated.h"

UCLASS(Abstract)
class FORTNITEGAMEFRAMEWORK_API UStateTreeTaskObject : public UStateTreeTaskBlueprintBase
{
	GENERATED_BODY()

public:
	UStateTreeTaskObject(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(EditDefaultsOnly, Category="TaskObject")
	bool bReplicates;

};

