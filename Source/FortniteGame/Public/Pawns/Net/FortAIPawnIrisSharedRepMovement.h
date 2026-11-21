// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Pawns/FortAIPawn.h"
#include "FortAIPawnIrisSharedRepMovement.generated.h"

UCLASS(Transient)
class UFortAIPawnIrisSharedRepMovement : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_FastSharedReplication();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_FastSharedReplication)
	FFortAISharedRepMovement AISharedRepMovement;

};

