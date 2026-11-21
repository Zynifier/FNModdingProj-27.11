// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Misc/DateTime.h"
#include "FortMediaRegionLockComponent.generated.h"

class AFortPlayerController;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_SixParams(FMediaRegionLockCanPlayContentInRegionComplete, bool, bResolved, bool, bApproved, FString, InURL, FString, Limits, FString, ContentId, const bool, bBulk);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FMediaRegionLockLocaleComplete, FString, Continent, FString, Country, const TArray<FString>&, Subdivisions);

USTRUCT(BlueprintType)
struct FMeshRegionLockData_Base
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="MeshRegionLockData_Base")
	FString RegionData;

	UPROPERTY(BlueprintReadWrite, Category="MeshRegionLockData_Base")
	bool Replicated;

};

USTRUCT(BlueprintType)
struct FMeshRegionLockData_Bool : public FMeshRegionLockData_Base
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="MeshRegionLockData_Bool")
	bool Data;

};

USTRUCT(BlueprintType)
struct FMeshRegionLockData_DateTime : public FMeshRegionLockData_Base
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="MeshRegionLockData_DateTime")
	FDateTime Data;

};

USTRUCT(BlueprintType)
struct FMeshRegionLockData_Float : public FMeshRegionLockData_Base
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="MeshRegionLockData_Float")
	float Data;

};

USTRUCT(BlueprintType)
struct FMeshRegionLockData_Int : public FMeshRegionLockData_Base
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="MeshRegionLockData_Int")
	int32 Data;

};

USTRUCT(BlueprintType)
struct FMeshRegionLockData_Int64 : public FMeshRegionLockData_Base
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="MeshRegionLockData_Int64")
	int64 Data;

};

USTRUCT(BlueprintType)
struct FMeshRegionLockData_String : public FMeshRegionLockData_Base
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="MeshRegionLockData_String")
	FString Data;

};

USTRUCT(BlueprintType)
struct FMeshRegionLockData_Tracker
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="MeshRegionLockData_Tracker")
	TArray<FString> RegionLockDatas;

};

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UFortMediaRegionLockComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void GetLocale(const AFortPlayerController* FortPC);

	UFUNCTION(BlueprintCallable)
	void GetRegionLockApproval(const AFortPlayerController* FortPC, const FString& UseURL, const FString& Data);

	UFUNCTION(BlueprintCallable)
	static void MeshAddRegionTrackerValue(UPARAM(ref) FMeshRegionLockData_Tracker& InTracker, const FString& InRegionData);

	UFUNCTION(BlueprintCallable)
	static void MeshAddRegionValue_Bool(const bool bInBool, UPARAM(ref) TArray<FMeshRegionLockData_Bool>& InArray, const FString& InRegionData);

	UFUNCTION(BlueprintCallable)
	static void MeshAddRegionValue_DateTime(const FDateTime InDateTime, UPARAM(ref) TArray<FMeshRegionLockData_DateTime>& InArray, const FString& InRegionData);

	UFUNCTION(BlueprintCallable)
	static void MeshAddRegionValue_Float(const float InFloat, UPARAM(ref) TArray<FMeshRegionLockData_Float>& InArray, const FString& InRegionData);

	UFUNCTION(BlueprintCallable)
	static void MeshAddRegionValue_Int(const int32 InInt, UPARAM(ref) TArray<FMeshRegionLockData_Int>& InArray, const FString& InRegionData);

	UFUNCTION(BlueprintCallable)
	static void MeshAddRegionValue_Int64(const int64 InInt64, UPARAM(ref) TArray<FMeshRegionLockData_Int64>& InArray, const FString& InRegionData);

	UFUNCTION(BlueprintCallable)
	static void MeshAddRegionValue_String(const FString InString, UPARAM(ref) TArray<FMeshRegionLockData_String>& InArray, const FString& InRegionData);

	UFUNCTION(BlueprintCallable)
	static bool MeshGetRegionValue_Bool(const FString& InFind, UPARAM(ref) TArray<FMeshRegionLockData_Bool>& InArray, FMeshRegionLockData_Bool& OutItem);

	UFUNCTION(BlueprintCallable)
	static bool MeshGetRegionValue_DateTime(const FString& InFind, UPARAM(ref) TArray<FMeshRegionLockData_DateTime>& InArray, FMeshRegionLockData_DateTime& OutItem);

	UFUNCTION(BlueprintCallable)
	static bool MeshGetRegionValue_Float(const FString& InFind, UPARAM(ref) TArray<FMeshRegionLockData_Float>& InArray, FMeshRegionLockData_Float& OutItem);

	UFUNCTION(BlueprintCallable)
	static bool MeshGetRegionValue_Int(const FString& InFind, UPARAM(ref) TArray<FMeshRegionLockData_Int>& InArray, FMeshRegionLockData_Int& OutItem);

	UFUNCTION(BlueprintCallable)
	static bool MeshGetRegionValue_Int64(const FString& InFind, UPARAM(ref) TArray<FMeshRegionLockData_Int64>& InArray, FMeshRegionLockData_Int64& OutItem);

	UFUNCTION(BlueprintCallable)
	static bool MeshGetRegionValue_String(const FString& InFind, UPARAM(ref) TArray<FMeshRegionLockData_String>& InArray, FMeshRegionLockData_String& OutItem);

	UFUNCTION(BlueprintCallable)
	static bool MeshRemoveRegionTrackerValue(UPARAM(ref) FMeshRegionLockData_Tracker& InTracker, const FString& InRegionData);

	UFUNCTION(BlueprintCallable)
	static void MeshRemoveRegionValue_Bool(UPARAM(ref) TArray<FMeshRegionLockData_Bool>& InArray, const FString& InRegionData);

	UFUNCTION(BlueprintCallable)
	static void MeshRemoveRegionValue_DateTime(UPARAM(ref) TArray<FMeshRegionLockData_DateTime>& InArray, const FString& InRegionData);

	UFUNCTION(BlueprintCallable)
	static void MeshRemoveRegionValue_Float(UPARAM(ref) TArray<FMeshRegionLockData_Float>& InArray, const FString& InRegionData);

	UFUNCTION(BlueprintCallable)
	static void MeshRemoveRegionValue_Int(UPARAM(ref) TArray<FMeshRegionLockData_Int>& InArray, const FString& InRegionData);

	UFUNCTION(BlueprintCallable)
	static void MeshRemoveRegionValue_Int64(UPARAM(ref) TArray<FMeshRegionLockData_Int64>& InArray, const FString& InRegionData);

	UFUNCTION(BlueprintCallable)
	static void MeshRemoveRegionValue_String(UPARAM(ref) TArray<FMeshRegionLockData_String>& InArray, const FString& InRegionData);

	UFUNCTION(BlueprintCallable)
	void SetEventCallback(bool bSet);

	UPROPERTY(BlueprintAssignable)
	FMediaRegionLockLocaleComplete OnMediaRegionLockLocaleComplete;

	UPROPERTY(BlueprintAssignable)
	FMediaRegionLockCanPlayContentInRegionComplete OnRegionLockCanPlayContentInRegionComplete;

};

