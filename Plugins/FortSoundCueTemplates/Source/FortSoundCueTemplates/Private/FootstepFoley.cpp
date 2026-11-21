// Copyright Epic Games, Inc. All Rights Reserved.

#include "FootstepFoley.h"
#include "GameplayTagsManager.h"
#include "Sound/SoundWave.h"

UFootstepFoley::UFootstepFoley(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITORONLY_DATA
	bUsingStances = true;
#endif
}

void UFootstepFoley::PostInitProperties()
{
	Super::PostInitProperties();

#if WITH_EDITOR
	PopulateStepTypes();
#endif
}

#if WITH_EDITOR
FString UFootstepFoley::GenerateDefaultNewAssetName(const TArray<TWeakObjectPtr<USoundWave>>& Waves) const
{
	FString StepTypeName;
	for (const TWeakObjectPtr<USoundWave>& Wave : Waves)
	{
		if (!StepTypeName.IsEmpty())
		{
			break;
		}

		if (Wave.IsValid())
		{
			const FString WaveName = Wave->GetName();
			for (const FString& StepType : StepTypes)
			{
				if (WaveName.Contains(StepType))
				{
					StepTypeName = StepType;
					break;
				}
			}
		}
	}

	return FString::Format(TEXT("Foley_FS_{0}"), { StepTypeName.IsEmpty() ? FString(TEXT("None")) : StepTypeName });
}

void UFootstepFoley::PopulateStepTypes()
{
	if (StepTypes.Num() == 0)
	{
		UGameplayTagsManager& TagsManager = UGameplayTagsManager::Get();
		const FGameplayTag StepTypeTag = TagsManager.RequestGameplayTag(FName(TEXT("SoundLibrary.ID.StepType")));
		if (const TSharedPtr<FGameplayTagNode> StepTypeNode = TagsManager.FindTagNode(StepTypeTag))
		{
			for (const TSharedPtr<FGameplayTagNode>& ChildNode : StepTypeNode->GetChildTagNodes())
			{
				if (ChildNode)
				{
					StepTypes.Add(ChildNode->GetSimpleTagName().ToString());
				}
			}
		}
	}
}
#endif
