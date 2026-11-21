// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "FortAnimInputEvent.generated.h"

class UAnimInstance;
class UFortAnimInputEvent;
class UFortAnimInputEvent_AnimClass;
class UFortAnimInputEvent_Bool;
class UFortAnimInputEvent_Float;
class UFortAnimInputEvent_Vector;

UCLASS(MinimalAPI, BlueprintType)
class UFortAnimInputEvent : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static UFortAnimInputEvent* CreateAnimInputEvent(FName InEventName);

	UFUNCTION(BlueprintPure)
	bool IsNamed(FName InEventName) const;

	UPROPERTY(BlueprintReadWrite, Category="FortAnimInputEvent")
	FName EventName;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortAnimInputEvent_AnimClass : public UFortAnimInputEvent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static UFortAnimInputEvent_AnimClass* CreateAnimInputEvent_AnimClass(FName InEventName, TSubclassOf<UAnimInstance> InValue);

	UPROPERTY(BlueprintReadWrite, Category="FortAnimInputEvent_AnimClass")
	TSubclassOf<UAnimInstance> Value;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortAnimInputEvent_Bool : public UFortAnimInputEvent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static UFortAnimInputEvent_Bool* CreateAnimInputEvent_Bool(FName InEventName, bool bInValue);

	UPROPERTY(BlueprintReadWrite, Category="FortAnimInputEvent_Bool")
	bool bValue;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortAnimInputEvent_Float : public UFortAnimInputEvent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static UFortAnimInputEvent_Float* CreateAnimInputEvent_Float(FName InEventName, float InValue);

	UPROPERTY(BlueprintReadWrite, Category="FortAnimInputEvent_Float")
	float Value;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortAnimInputEvent_Vector : public UFortAnimInputEvent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static UFortAnimInputEvent_Vector* CreateAnimInputEvent_Vector(FName InEventName, FVector InValue);

	UPROPERTY(BlueprintReadWrite, Category="FortAnimInputEvent_Vector")
	FVector Value;

};

