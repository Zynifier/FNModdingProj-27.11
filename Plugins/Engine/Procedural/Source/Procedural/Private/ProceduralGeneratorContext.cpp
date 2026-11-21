// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProceduralGeneratorContext.h"

void UProceduralGeneratorContext::ClearGeneratedContent()
{
}

bool UProceduralGeneratorContext::Generate()
{
	return false;
}

TArray<UProceduralGeneratorContext*> UProceduralGeneratorContext::GetGeneratedContexts() const
{
	return TArray<UProceduralGeneratorContext*>();
}

void UProceduralGeneratorContext::GetOrCreateGeneratorContext(UProceduralGenerator* Generator, UProceduralGeneratorContext*& Context)
{
}

void UProceduralGeneratorContext::OnClearGeneratedContent_Implementation()
{
}

bool UProceduralGeneratorContext::OnGenerate_Implementation()
{
	return false;
}
