// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PFWExample_GameObject.generated.h"

class UPFWExample_SubGameObject;

USTRUCT()
struct FPFWExample_Struct
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 IntValue;

	UPROPERTY()
	float FloatValue;

	UPROPERTY(Transient)
	TArray<int32> IntValueNonPersistent;

};

UCLASS()
class FORTNITEGAME_API UPFWExample_GameObject : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FName PersistentName;

	UPROPERTY()
	int32 IntValue;

	UPROPERTY()
	float FloatValue;

	UPROPERTY()
	FString StringValue;

	UPROPERTY()
	FPFWExample_Struct StructValue;

	UPROPERTY()
	TArray<FPFWExample_Struct> StructArrayValue;

	UPROPERTY()
	TArray<TObjectPtr<UPFWExample_SubGameObject>> SubObjectArray;

	UPROPERTY()
	TArray<int32> IntValueNonPersistent;

	UPROPERTY()
	TArray<float> FloatValueNonPersistent;

	UPROPERTY()
	TArray<FString> StringValueNonPersistent;

};

UCLASS()
class FORTNITEGAME_API UPFWExample_SubGameObject : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	FName PersistentName;

	UPROPERTY()
	int32 IntValue;

	UPROPERTY(Transient)
	TArray<int32> IntValueNonPersistent;

};

