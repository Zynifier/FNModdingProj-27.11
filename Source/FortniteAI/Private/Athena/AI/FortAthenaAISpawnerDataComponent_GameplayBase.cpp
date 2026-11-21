// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/AI/FortAthenaAISpawnerDataComponent_GameplayBase.h"

bool UFortAthenaAIRuntimeParameters_AIConvert::GetCanBeConverted() const
{
	return false;
}

bool UFortAthenaAIRuntimeParameters_AIConvert::GetCanBeConvertedFromDBNO() const
{
	return false;
}

bool UFortAthenaAIRuntimeParameters_AIConvert::GetForceKillWhenConverterDies() const
{
	return false;
}

bool UFortAthenaAIRuntimeParameters_AIConvert::GetForceKillWhenUnconverted() const
{
	return false;
}

const TArray<FPickupTagConvertInfo>& UFortAthenaAIRuntimeParameters_AIConvert::GetPickupTagConvertInfos() const
{
	static TArray<FPickupTagConvertInfo> Dummy;
	return Dummy;
}

void UFortAthenaAIRuntimeParameters_AIConvert::SetCanBeConverted(const bool bInCanBeConverted)
{
}

void UFortAthenaAIRuntimeParameters_AIConvert::SetCanBeConvertedFromDBNO(const bool bInCanBeConvertedFromDBNO)
{
}

void UFortAthenaAIRuntimeParameters_AIConvert::SetForceKillWhenConverterDies(const bool bInForceKillWhenConverterDies)
{
}

void UFortAthenaAIRuntimeParameters_AIConvert::SetForceKillWhenUnconverted(const bool bInForceKillWhenUnconverted)
{
}

float UFortAthenaAISpawnerDataComponent_GameplayBase::GetGlobalSpeedMultiplier_Implementation() const
{
	return float();
}

void UFortAthenaAISpawnerDataComponent_GameplayBase::SetCanBeConverted(const bool bInCanBeConverted)
{
}

void UFortAthenaAISpawnerDataComponent_GameplayBase::SetCopyConverterSpecificRelations(const bool bInCopyConverterSpecificRelations)
{
}

bool UFortAthenaAISpawnerDataComponent_GameplayBase::ShouldOverrideGlobalSpeedMultiplier_Implementation() const
{
	return false;
}
