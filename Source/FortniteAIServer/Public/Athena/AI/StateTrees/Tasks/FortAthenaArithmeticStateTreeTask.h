// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayInteractionsTypes.h"
#include "StateTreeTaskBase.h"
#include "StateTreeTypes.h"
#include "FortAthenaArithmeticStateTreeTask.generated.h"

UENUM()
enum class EFortAthenaArithmeticOperation : uint8
{
	Add = 0,
	Subtract = 1,
	Multiply = 2,
	Divide = 3,
};

USTRUCT(meta=(Hidden))
struct FFortAthenaArithmeticStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Parameter")
	EGameplayInteractionTaskTrigger OperationTrigger;

	UPROPERTY(EditAnywhere, Category="Parameter")
	EFortAthenaArithmeticOperation Operation;

};

USTRUCT(meta=(DisplayName="(Fortnite) Arithmetic: Operation Int"))
struct FFortAthenaIntArithmeticStateTreeTask : public FFortAthenaArithmeticStateTreeTask
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortAthenaIntArithmeticStateTreeTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Parameter")
	int32 FirstOperand;

	UPROPERTY(EditAnywhere, Category="Parameter")
	int32 SecondOperand;

	UPROPERTY(EditAnywhere, Category="Parameter", meta=(BaseStruct="/Script/FortniteAIServer.FortAthenaIntStateTreeParameter"))
	FStateTreeStructRef ReferencedResult;

};

