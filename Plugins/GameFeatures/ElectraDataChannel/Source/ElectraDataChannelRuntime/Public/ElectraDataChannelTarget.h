// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ElectraDataChannelTarget.generated.h"

UCLASS()
class ELECTRADATACHANNELRUNTIME_API AElectraDataChannelTarget : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="DataChannel")
	FString GetTargetAlias() const;

	UFUNCTION(BlueprintCallable, Category="DataChannel")
	void SetTargetAlias(const FString& InAlias);

};

