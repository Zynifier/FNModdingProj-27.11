// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortUserDefinedBehaviorSetNode.generated.h"

class UFortUserDefinedBehaviorSetContainer;

UCLASS(DefaultToInstanced, EditInlineNew, MinimalAPI, meta=(DisplayName="Behavior Set Node (Valkyrie)"))
class UFortUserDefinedBehaviorSetNode : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Conditions")
	FName TriggeringPropertyName;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Behavior")
	TArray<TSoftClassPtr<UFortUserDefinedBehaviorSetContainer>> BehaviorSets;

};

