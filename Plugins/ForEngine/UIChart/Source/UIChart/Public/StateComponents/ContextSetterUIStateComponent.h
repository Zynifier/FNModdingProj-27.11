// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UIStateComponent.h"
#include "ContextSetterUIStateComponent.generated.h"

class UContextSetterUIStateComponentConfiguration;

USTRUCT()
struct FContextSetterClearEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ContextSetterClearEntry")
	FGameplayTag Key;

};

USTRUCT()
struct FContextSetterSetEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ContextSetterSetEntry")
	FGameplayTag Key;

	UPROPERTY(EditAnywhere, Category="ContextSetterSetEntry")
	FString Value;

};

USTRUCT()
struct FContextSetterChanges
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ContextSetterChanges")
	TArray<FContextSetterSetEntry> ValuesToSet;

	UPROPERTY(EditAnywhere, Category="ContextSetterChanges")
	TArray<FContextSetterClearEntry> ValuesToClear;

};

UCLASS()
class UICHART_API UContextSetterUIStateComponent : public UUIStateComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Export, Category="ContextSetterUIStateComponent", meta=(EditInline="true"))
	UContextSetterUIStateComponentConfiguration* Configuration;

};

UCLASS()
class UICHART_API UContextSetterUIStateComponentConfiguration : public UUIStateComponentConfiguration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ContextSetterUIStateComponentConfiguration")
	FContextSetterChanges ActivationChanges;

	UPROPERTY(EditAnywhere, Category="ContextSetterUIStateComponentConfiguration")
	FContextSetterChanges DeactivationChanges;

};

