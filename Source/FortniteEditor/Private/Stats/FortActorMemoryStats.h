// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortActorMemoryStats.generated.h"

class AActor;

UCLASS(Transient, MinimalAPI, meta=(DisplayName="Actor Memory Stats"))
class UFortActorMemoryStats : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, AssetRegistrySearchable, Category="Stats", meta=(ColumnWidth="200", DisplayName="Actor(s)"))
	TArray<TWeakObjectPtr<AActor>> Actors;

	UPROPERTY(VisibleAnywhere, AssetRegistrySearchable, Category="Stats", meta=(ColumnWidth="200", DisplayName="Type"))
	FString Type;

	UPROPERTY(VisibleAnywhere, AssetRegistrySearchable, Category="Stats", meta=(ColumnWidth="70", DisplayName="Type Count", ShowTotal="true"))
	int32 TypeCount;

	UPROPERTY(VisibleAnywhere, AssetRegistrySearchable, Category="Stats", meta=(ColumnWidth="70", DisplayName="Actor(s) Size", ShowTotal="true", Unit="KB"))
	float ActorSize;

	UPROPERTY(VisibleAnywhere, AssetRegistrySearchable, Category="Stats", meta=(ColumnWidth="110", DisplayName="Asset Estimated Size", Unit="KB"))
	float AssetEstimatedSize;

};

