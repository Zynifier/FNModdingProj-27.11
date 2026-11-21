// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI/Components/FortAIComponent_Telemetry.h"

UFortAthenaAITelemetryData* UFortAIComponent_Telemetry::GetOrCreateTelemetryData(const TSubclassOf<UFortAthenaAITelemetryData> TelemetryDataClass)
{
	return nullptr;
}

void UFortAIComponent_Telemetry::OnDidDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void UFortAIComponent_Telemetry::OnPawnDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void UFortAIComponent_Telemetry::OnTetheredFollowerChanged(AFortPawn* NewFollower, AFortPawn* OldFollower)
{
}

UFortAthenaAITelemetryData* UFortAthenaAITelemetryFunctionLibrary::GetOrCreateAITelemetryData(const AActor* Owner, const TSubclassOf<UFortAthenaAITelemetryData> TelemetryDataClass)
{
	return nullptr;
}
