// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortGenericRecord.h"
#include "FortZoneRecord.h"
#include "FortDeployableBaseRecord.generated.h"

UCLASS()
class UFortDeployableBaseRecord : public UFortGenericRecord
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<FFortActorRecord> Actors;

	UPROPERTY(Transient)
	uint8 bNeedsFullActorSave : 1;

};

