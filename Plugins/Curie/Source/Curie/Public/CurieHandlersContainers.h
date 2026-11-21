// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CurieHandlersContainers.generated.h"

class UCurieElementAttachConditionHandler;
class UCurieElementAttachHandler;
class UCurieElementInteractWithContainerHandler;
class UCurieElementInteractWithElementHandler;
class UCurieElementInteractWithMaterialHandler;

USTRUCT()
struct FCurieElementAttachConditionHandlersContainer
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<TObjectPtr<UCurieElementAttachConditionHandler>> Handlers;

};

USTRUCT()
struct FCurieElementAttachHandlersContainer
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<TObjectPtr<UCurieElementAttachHandler>> Handlers;

};

USTRUCT()
struct FCurieElementInteractWithContainerHandlersContainer
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<TObjectPtr<UCurieElementInteractWithContainerHandler>> Handlers;

};

USTRUCT()
struct FCurieElementInteractWithElementHandlersContainer
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<TObjectPtr<UCurieElementInteractWithElementHandler>> Handlers;

};

USTRUCT()
struct FCurieElementInteractWithMaterialHandlersContainer
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TArray<TObjectPtr<UCurieElementInteractWithMaterialHandler>> Handlers;

};

