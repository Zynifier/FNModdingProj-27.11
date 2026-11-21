// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI/FortAIFunctionLibrary.h"

UAthenaAISpawner* UFortAIFunctionLibrary::GetAISpawner(UObject* WorldContextObject)
{
	return nullptr;
}

UFortAthenaAIRuntimeParameters* UFortAIFunctionLibrary::GetOrCreateAIRuntimeParameters(const AAIController* AIController, const TSubclassOf<UFortAthenaAIRuntimeParameters> ParametersClass)
{
	return nullptr;
}

bool UFortAIFunctionLibrary::IsConcealedByPerceptionModifiers(const UObject* WorldContextObject, FVector ObserverLocation, FVector TargetLocation, float& OutConcealment)
{
	return false;
}

void UFortAIFunctionLibrary::MakeNoiseEvent(AActor* NoiseMaker, const float MaxRange, const FName NoiseTag)
{
}

void UFortAIFunctionLibrary::MakeNoiseEventAtLocation(AActor* NoiseMaker, const float MaxRange, const FVector& NoiseLocation, const FName NoiseTag)
{
}

void UFortAIFunctionLibrary::RequestNavUpdateForBuilding(ABuildingActor* BuildingActor)
{
}

void UFortAIFunctionLibrary::SetHearingRange(AActor* AIAgent, float Range)
{
}

bool UFortAIFunctionLibrary::TeleportAIPawn(AFortAIPawn* AIPawn, FVector DestLocation, FRotator DestRotation, bool bIgnoreCollision)
{
	return false;
}
