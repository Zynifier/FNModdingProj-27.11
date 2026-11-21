// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortMeshNetworkActor.generated.h"

class UMeshNetworkComponent;
class UObject;

UCLASS(BlueprintType, Blueprintable)
class AFortMeshNetworkActor : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Export, Category="FortMeshNetworkActor", meta=(EditInline="true"))
	TObjectPtr<UMeshNetworkComponent> MeshNetworkComponent;

};

UCLASS()
class UFortMeshNetworkFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(DefaultToSelf="WorldContextObject", DeprecatedFunction, HidePin="WorldContextObject"))
	static void FireEvent_MeshHeartbeat(const UObject* WorldContextObject);

};

