// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FortUISpecialEventSubsystem.generated.h"

UENUM(BlueprintType)
enum EFortUISpecialEvents
{
	NoEvent = 0,
	FritTemp = 1,
};

UCLASS()
class UFortUISpecialEventSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSpecialUIEventDelegate, TEnumAsByte<EFortUISpecialEvents>, InEventName);

public:
	UFUNCTION(BlueprintCallable)
	void CallTemporarySpecialUIEvent(EFortUISpecialEvents InNewTemporaryEvent);

	UFUNCTION(BlueprintCallable)
	EFortUISpecialEvents GetCurrentUIEventState();

	UFUNCTION(BlueprintCallable)
	void SetCurrentUISpecialEventState(EFortUISpecialEvents InNewEventState);

	UPROPERTY(BlueprintAssignable, Category="UI Events")
	FSpecialUIEventDelegate OnNewUISpecialEventState;

	UPROPERTY(BlueprintAssignable, Category="UI Events")
	FSpecialUIEventDelegate OnTemporarySpecialUIEvent;

};

