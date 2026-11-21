// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "Player/EntityActorPlayerComponent.h"
#include "DatastoreComponentBase.generated.h"

class UDatastoreComponentBase;

USTRUCT()
struct FDatastoreEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	// TODO: should key include namespace or type information? Not sure if we need namespaces or just use multiple datastores for organisation
// TODO: most keys will be known ahead of time, verse toolchain could generate them, but we still need to support dynamic key generation too

	UPROPERTY()
	FName KeyName;

	// TODO: Support more types, including references to other datastores

	UPROPERTY()
	FString ValueData;

};

USTRUCT()
struct FDatastoreState : public FFastArraySerializer
{
	GENERATED_BODY()

private:
	// TODO: map or set might be more suitable, if theres an equivalent of FastArraySerializer for them

	UPROPERTY()
	TArray<FDatastoreEntry> EntriesArray;

	UPROPERTY(NotReplicated)
	TObjectPtr<UDatastoreComponentBase> OwningComponent;

};

UCLASS(Abstract)
class VGAMEPLAYRST_API UDatastoreComponentBase : public UEntityActorPlayerComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Replicated)
	FDatastoreState ReplicatedDatastoreState;

};

