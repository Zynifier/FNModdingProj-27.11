// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Iris/Serialization/NetSerializerConfig.h"
#include "ReplicatedLocalizedDocumentNetSerializer.generated.h"

USTRUCT()
struct FReplicatedLocalizedDocumentIdAndSourceLang
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Id;

	UPROPERTY()
	FString SourceLang;

};

USTRUCT()
struct FReplicatedLocalizedDocumentNetSerializerConfig : public FNetSerializerConfig
{
	GENERATED_BODY()

};

