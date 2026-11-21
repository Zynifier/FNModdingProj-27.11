// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PrimitiveModularCrosstalkInterface.generated.h"

class UObject;

UENUM()
enum class EPrimitiveCrosstalkFunctions : uint8
{
	SendTagAsPayload = 0,
	SendTaggedObjectPayload = 1,
	SendTaggedStringPayload = 2,
	SendTaggedIntPayload = 3,
	GetTaggedObjectPayload = 4,
	GetTaggedStringPayload = 5,
	GetTaggedIntPayload = 6,
	BindNoParamEventToTaggedDelegate = 7,
	UnbindNoParamEventFromTaggedDelegate = 8,
	UnbindObjectCallbacksFromAllTaggedDelegates = 9,
};

USTRUCT()
struct FPrimitiveCrosstalkNameArray
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, NoClear, EditFixedSize, Category="PrimitiveCrosstalkNameArray")
	TArray<FName> SupportedFunctions;

};

UINTERFACE(MinimalAPI, meta=(CannotImplementInterfaceInBlueprint))
class UPrimitiveModularCrosstalkInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IPrimitiveModularCrosstalkInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="GameFeatures|Crosstalk")
	virtual void BindNoParamEventToTaggedDelegate(const FName& DelegateTag, UObject* Object, const FName& CallbackEventName);

	UFUNCTION(BlueprintCallable, Category="GameFeatures|Crosstalk")
	virtual int32 GetTaggedIntPayload(const FName& Tag);

	UFUNCTION(BlueprintCallable, Category="GameFeatures|Crosstalk")
	virtual UObject* GetTaggedObjectPayload(const FName& Tag);

	UFUNCTION(BlueprintCallable, Category="GameFeatures|Crosstalk")
	virtual FString GetTaggedStringPayload(const FName& Tag);

	UFUNCTION(BlueprintCallable, Category="GameFeatures|Crosstalk")
	virtual void SendTagAsPayload(const FName& Tag);

	UFUNCTION(BlueprintCallable, Category="GameFeatures|Crosstalk")
	virtual void SendTaggedIntPayload(const FName& Tag, int32 Payload);

	UFUNCTION(BlueprintCallable, Category="GameFeatures|Crosstalk")
	virtual void SendTaggedObjectPayload(const FName& Tag, UObject* Payload);

	UFUNCTION(BlueprintCallable, Category="GameFeatures|Crosstalk")
	virtual void SendTaggedStringPayload(const FName& Tag, const FString& Payload);

	UFUNCTION(BlueprintCallable, Category="GameFeatures|Crosstalk")
	virtual void UnbindNoParamEventFromTaggedDelegate(const FName& DelegateTag, UObject* Object);

	UFUNCTION(BlueprintCallable, Category="GameFeatures|Crosstalk")
	virtual void UnbindObjectCallbacksFromAllTaggedDelegates(UObject* Object);

};

