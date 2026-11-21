// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DataAssetDirectoryTestAsset.generated.h"

class UDataAssetDirectorySimpleObject;

UENUM(BlueprintType)
enum class EDataAssetDirectoryTestEnum : uint8
{
	A = 0,
	B = 1,
	C = 2,
	D = 3,
};

USTRUCT(BlueprintType)
struct FDataAssetDirectoryTestPODStruct
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Test", meta=(Patchable))
	EDataAssetDirectoryTestEnum EnumProperty;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Test", meta=(Patchable))
	int32 IntProperty;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Test", meta=(Patchable))
	float FloatProperty;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Test", meta=(Patchable))
	bool BoolProperty;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Test", meta=(Patchable))
	FString StringProperty;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Test", meta=(Patchable))
	FName NameProperty;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Test", meta=(Patchable))
	FText TextProperty;

};

USTRUCT(BlueprintType)
struct FDataAssetDirectoryTestSimpleStruct
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Test", meta=(Patchable))
	int32 IntProperty;

};

UCLASS(BlueprintType, meta=(Patchable="KeyProperty=DataAssetDirectorySimpleObject"))
class DATAASSETDIRECTORY_API UDataAssetDirectorySimpleObject : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Test", meta=(Patchable))
	int32 IntProperty;

};

UCLASS(BlueprintType, meta=(Patchable="KeyProperty=DataAssetDirectoryTestArrayAsset"))
class DATAASSETDIRECTORY_API UDataAssetDirectoryTestArrayAsset : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Test")
	TArray<int32> IntArray;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Test")
	TArray<FDataAssetDirectoryTestSimpleStruct> SimpleStructArray;

};

UCLASS(BlueprintType, meta=(Patchable="KeyProperty=DataAssetDirectoryTestMapAsset"))
class DATAASSETDIRECTORY_API UDataAssetDirectoryTestMapAsset : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Test", meta=(Patchable))
	TMap<FString, int32> StringIntMap;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Test", meta=(Patchable))
	TMap<FString, int32> ShrinkStringIntMap;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Test", meta=(Patchable))
	TMap<FString, int32> GrowStringIntMap;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Test", meta=(Patchable))
	TMap<int32, FDataAssetDirectoryTestSimpleStruct> IntStructMap;

};

UCLASS(BlueprintType, meta=(Patchable="KeyProperty=DataAssetDirectoryTestObjectAsset"))
class DATAASSETDIRECTORY_API UDataAssetDirectoryTestObjectAsset : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Test")
	TObjectPtr<UDataAssetDirectorySimpleObject> SimpleObject;

};

UCLASS(BlueprintType, meta=(Patchable="KeyProperty=DataAssetDirectoryTestPODAsset"))
class DATAASSETDIRECTORY_API UDataAssetDirectoryTestPODAsset : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Test")
	FString AssetName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Test", meta=(Patchable))
	EDataAssetDirectoryTestEnum EnumProperty;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Test", meta=(Patchable))
	int32 IntProperty;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Test", meta=(Patchable))
	float FloatProperty;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Test", meta=(Patchable))
	bool BoolProperty;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Test", meta=(Patchable))
	FString StringProperty;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Test", meta=(Patchable))
	FName NameProperty;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Test", meta=(Patchable))
	FText TextProperty;

};

UCLASS(BlueprintType, meta=(Patchable="KeyProperty=DataAssetDirectoryTestStructAsset"))
class DATAASSETDIRECTORY_API UDataAssetDirectoryTestStructAsset : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Test")
	FDataAssetDirectoryTestPODStruct TestStruct;

};

