// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Iris/Serialization/NetSerializerConfig.h"
#include "FortCurieVoxelReplicationDataNetSerializer.generated.h"

USTRUCT()
struct FFortCurieVoxelReplicationDataNetSerializerConfig : public FNetSerializerConfig
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint32 MaxAllowedDataBits;

};

