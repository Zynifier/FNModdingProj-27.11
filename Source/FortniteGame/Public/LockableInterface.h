// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LockableInterface.generated.h"

class UPrimitiveComponent;

UENUM(BlueprintType)
enum class ELockState : uint8
{
	INVALID = 0,
	UNLOCKED = 1,
	LOCKED = 2,
};

UINTERFACE()
class ULockableInterface : public UInterface
{
	GENERATED_BODY()
};

class ILockableInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="Lockable Interface")
	TArray<UPrimitiveComponent*> GetComponentToLock();

	UFUNCTION(BlueprintImplementableEvent, Category="Lockable Interface")
	void OnLocked();

	UFUNCTION(BlueprintImplementableEvent, Category="Lockable Interface")
	void OnUnLocked();

};

