// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAthenaTutorialTargetInfo.generated.h"

class AActor;
class ABuildingProp;
class AFortAIPawn;

USTRUCT(BlueprintType)
struct FFortAthenaTutorial_AiTargetInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaTutorial_AiTargetInfo")
	TObjectPtr<AActor> TargetMarker;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaTutorial_AiTargetInfo")
	TObjectPtr<AFortAIPawn> TargetActor;

};

USTRUCT(BlueprintType)
struct FFortAthenaTutorial_TargetInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaTutorial_TargetInfo")
	TObjectPtr<AActor> TargetMarker;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAthenaTutorial_TargetInfo")
	TObjectPtr<ABuildingProp> TargetActor;

};

