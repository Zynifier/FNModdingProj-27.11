// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "FortAthenaBTTask_SetAggressiveDriving.generated.h"

UCLASS()
class UFortAthenaBTTask_SetAggressiveDriving : public UBTTaskNode
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Vehicle", meta=(AllowPrivateAccess="true"))
	bool bAggressiveDriving;

};

