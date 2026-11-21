// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DynamicDestructionObjectInterface.generated.h"

class UStaticMeshComponent;
enum class EDynamicDestructionResourceType : uint8;

UENUM(BlueprintType)
enum class EDynamicDestructionResourceType : uint8
{
	Invalid = 0,
	Wood = 1,
	//1

	Stone = 2,
	//2

	Metal = 3,
	//3

	Foliage = 4,
	//Explicitly adding some unused entries so FX can test with new types if they want to

	Unused_5 = 5,
	//5

	Unused_6 = 6,
	//6

	Unused_7 = 7,
	//7

	Unused_8 = 8,
};

UINTERFACE(MinimalAPI, BlueprintType)
class UDynamicDestructionObjectInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IDynamicDestructionObjectInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Dynamic Destruction")
	EDynamicDestructionResourceType GetDynamicDestructionResourceType() const;

	UFUNCTION(BlueprintNativeEvent, Category="Dynamic Destruction")
	void GetDynamicDestructionStaticMeshComponents(TArray<UStaticMeshComponent*>& OutFullFXStaticMeshComponents, TArray<UStaticMeshComponent*>& OutVisibilityOnlyStaticMeshComponents, TArray<UStaticMeshComponent*>& OutShadowProxyStaticMeshComponents);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Dynamic Destruction")
	bool IsDynamicDestructionObjectDestroyed() const;

	UFUNCTION(BlueprintNativeEvent, Category="Dynamic Destruction")
	void OnDynamicDestructionCanceled();

	UFUNCTION(BlueprintNativeEvent, Category="Dynamic Destruction")
	void OnDynamicDestructionDissolveFinished();

	UFUNCTION(BlueprintNativeEvent, Category="Dynamic Destruction")
	void OnDynamicDestructionEnded();

	UFUNCTION(BlueprintNativeEvent, Category="Dynamic Destruction")
	void OnDynamicDestructionStarted();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Dynamic Destruction")
	bool ShouldUseDynamicDestruction() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Dynamic Destruction")
	bool ShouldUseDynamicDestructionMaterial() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Dynamic Destruction")
	bool ShouldUseDynamicDestructionNiagaraSystem() const;

};

