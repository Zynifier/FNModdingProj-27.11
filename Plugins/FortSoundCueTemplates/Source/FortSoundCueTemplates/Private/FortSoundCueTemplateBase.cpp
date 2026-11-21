// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortSoundCueTemplateBase.h"
#include "AssetRegistry/AssetData.h"
#include "AudioParameter.h"
#include "Components/AudioComponent.h"
#include "FortSoundCueTemplateSettings.h"
#include "Sound/SoundCueNodes/FortSoundNodeLicensedContentSwitcher.h"
#include "Sound/SoundNodeAttenuation.h"
#include "Sound/SoundNodeDelay.h"
#include "Sound/SoundNodeDistanceCrossFade.h"
#include "Sound/SoundNodeModulator.h"
#include "Sound/SoundNodeModulatorContinuous.h"
#include "Sound/SoundNodeParamCrossFade.h"
#include "Sound/SoundNodeRandom.h"
#include "Sound/SoundNodeSoundClass.h"
#include "Sound/SoundNodeSwitch.h"
#include "Sound/SoundNodeWavePlayer.h"
#include "Sound/SoundWave.h"

#if WITH_EDITOR
#include "EdGraph/EdGraphNode.h"
#include "EdGraph/EdGraphPin.h"
#include "Editor.h"
#include "SoundCueGraph/SoundCueGraphNode_Base.h"
#endif

UFortSoundCueTemplateBase::UFortSoundCueTemplateBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITORONLY_DATA
	StartDelay = FVector2D::ZeroVector;
	PitchModulationRange = FVector2D::UnitVector;
	VolumeModulationRange = FVector2D::UnitVector;
#endif
}

bool UFortSoundCueTemplateBase::CanBeClusterRoot() const
{
	return true;
}

void UFortSoundCueTemplateBase::PostInitProperties()
{
	Super::PostInitProperties();
}

void UFortSoundCueTemplateBase::PreSave(FObjectPreSaveContext ObjectSaveContext)
{
	Super::PreSave(ObjectSaveContext);

#if WITH_EDITOR
	ValidateTemplateData();
#endif
}

void UFortSoundCueTemplateBase::PostLoad()
{
	Super::PostLoad();

#if WITH_EDITOR
	ValidateTemplateData();

	if (!SoundCueTemplateClass)
	{
		UpdateSoundCueTemplateClass();
	}

	UpdateTemplateDefaults();
#endif
}

void UFortSoundCueTemplateBase::Serialize(FArchive& Ar)
{
	Super::Serialize(Ar);
}

#if WITH_EDITOR
void UFortSoundCueTemplateBase::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.Property)
	{
		const FString Category = PropertyChangedEvent.Property->GetMetaData(TEXT("Category"));
		if (Category != TEXT("Auditioning"))
		{
			Super::PostEditChangeProperty(PropertyChangedEvent);
		}
	}

	UpdatePreviewParameters();
}

void UFortSoundCueTemplateBase::LoadTemplateDefaultSettings()
{
	UpdateSoundCueTemplateClass();
	UpdateTemplateDefaults();

	if (DefaultTemplateSettings)
	{
		SoundClassObject = DefaultTemplateSettings->SoundClass;
		AttenuationSettings = DefaultTemplateSettings->Attenuation;

		ConcurrencySet.Reset();
		ConcurrencySet.Add(DefaultTemplateSettings->Concurrency);

		SoundSubmixSends.Reset(DefaultTemplateSettings->SubmixSends.Num());
		for (const FFortSubmixPair& SubmixPair : DefaultTemplateSettings->SubmixSends)
		{
			if (SubmixPair.Submix)
			{
				FSoundSubmixSendInfo SubmixSendInfo;
				SubmixSendInfo.SoundSubmix = SubmixPair.Submix;
				SubmixSendInfo.SendLevel = SubmixPair.SendAmount;
				SoundSubmixSends.Add(SubmixSendInfo);
			}
		}

		BusSends.Reset(DefaultTemplateSettings->PostEffectBusSends.Num());
		for (const FFortBusPair& BusPair : DefaultTemplateSettings->PostEffectBusSends)
		{
			if (BusPair.SourceBus || BusPair.AudioBus)
			{
				FSoundSourceBusSendInfo BusSendInfo;
				BusSendInfo.SoundSourceBus = BusPair.SourceBus;
				BusSendInfo.AudioBus = BusPair.AudioBus;
				BusSendInfo.SendLevel = BusPair.SendAmount;
				BusSends.Add(BusSendInfo);
			}
		}

		PreEffectBusSends.Reset(DefaultTemplateSettings->PreEffectBusSends.Num());
		for (const FFortBusPair& BusPair : DefaultTemplateSettings->PreEffectBusSends)
		{
			if (BusPair.SourceBus || BusPair.AudioBus)
			{
				FSoundSourceBusSendInfo BusSendInfo;
				BusSendInfo.SoundSourceBus = BusPair.SourceBus;
				BusSendInfo.AudioBus = BusPair.AudioBus;
				BusSendInfo.SendLevel = BusPair.SendAmount;
				PreEffectBusSends.Add(BusSendInfo);
			}
		}

		TemplateVolumeMultiplier = DefaultTemplateSettings->VolumeMultiplier;
		TemplatePitchMultiplier = DefaultTemplateSettings->PitchMultiplier;
	}
}

void UFortSoundCueTemplateBase::ApplyBaseSettings(USoundCue& SoundCue) const
{
	SoundCue.VolumeMultiplier = TemplateVolumeMultiplier;
	SoundCue.PitchMultiplier = TemplatePitchMultiplier;
	SoundCue.SoundClassObject = SoundClassObject;
	SoundCue.AttenuationSettings = AttenuationSettings;
}

void UFortSoundCueTemplateBase::ApplyConcurrencySettings(USoundCue& SoundCue) const
{
	SoundCue.ConcurrencySet = ConcurrencySet;
}

void UFortSoundCueTemplateBase::ApplySubmixSettings(USoundCue& SoundCue) const
{
	SoundCue.SoundSubmixSends = SoundSubmixSends;
}

void UFortSoundCueTemplateBase::ApplyBusSettings(USoundCue& SoundCue) const
{
	SoundCue.BusSends = BusSends;
	SoundCue.PreEffectBusSends = PreEffectBusSends;
}

void UFortSoundCueTemplateBase::ApplySettings(USoundCue& SoundCue) const
{
	ApplyBaseSettings(SoundCue);
	ApplyConcurrencySettings(SoundCue);
	ApplySubmixSettings(SoundCue);
	ApplyBusSettings(SoundCue);
}

USoundNode* UFortSoundCueTemplateBase::AddDelayNode(USoundCue& SoundCue, FFortSoundCueTemplateNodeParams& Params, const FVector2D& DelayRange) const
{
	if (DelayRange.IsNearlyZero())
	{
		return nullptr;
	}

	USoundNodeDelay* DelayNode = ConstructNode<USoundNodeDelay>(SoundCue, Params);
	DelayNode->DelayMin = DelayRange.X;
	DelayNode->DelayMax = DelayRange.Y;
	return DelayNode;
}

USoundNode* UFortSoundCueTemplateBase::AddModulatorNode(USoundCue& SoundCue, FFortSoundCueTemplateNodeParams& Params, const FVector2D& VolumeRange, const FVector2D& PitchRange) const
{
	if (VolumeRange.Equals(FVector2D::UnitVector) && PitchRange.Equals(FVector2D::UnitVector))
	{
		return nullptr;
	}

	USoundNodeModulator* ModulatorNode = ConstructNode<USoundNodeModulator>(SoundCue, Params);
	ModulatorNode->VolumeMax = VolumeRange.Y;
	ModulatorNode->VolumeMin = VolumeRange.X;
	ModulatorNode->PitchMax = PitchRange.Y;
	ModulatorNode->PitchMin = PitchRange.X;
	return ModulatorNode;
}

USoundNode* UFortSoundCueTemplateBase::AddContinuousModulatorNode(USoundCue& SoundCue, FFortSoundCueTemplateNodeParams& Params, const FModulatorContinuousParams& VolumeParams, const FModulatorContinuousParams& PitchParams) const
{
	USoundNodeModulatorContinuous* ModulatorNode = ConstructNode<USoundNodeModulatorContinuous>(SoundCue, Params);
	ModulatorNode->VolumeModulationParams = VolumeParams;
	ModulatorNode->PitchModulationParams = PitchParams;
	return ModulatorNode;
}

USoundNode* UFortSoundCueTemplateBase::AddParamCrossFadeNode(USoundCue& SoundCue, FFortSoundCueTemplateNodeParams& Params, const FName& ParamName, const TArray<FDistanceDatum>& CrossFadeInput) const
{
	if (ParamName.IsNone())
	{
		return nullptr;
	}

	USoundNodeParamCrossFade* CrossFadeNode = ConstructNode<USoundNodeParamCrossFade>(SoundCue, Params);
	CrossFadeNode->ParamName = ParamName;
	CrossFadeNode->CrossFadeInput = CrossFadeInput;
	return CrossFadeNode;
}

USoundNode* UFortSoundCueTemplateBase::AddSwitchNode(USoundCue& SoundCue, FFortSoundCueTemplateNodeParams& Params, const FName& ParamName) const
{
	if (ParamName.IsNone())
	{
		return nullptr;
	}

	USoundNodeSwitch* SwitchNode = ConstructNode<USoundNodeSwitch>(SoundCue, Params);
	SwitchNode->IntParameterName = ParamName;
	SwitchNode->InsertChildNode(0);
	return SwitchNode;
}

USoundNode* UFortSoundCueTemplateBase::AddSoundClassNode(USoundCue& SoundCue, FFortSoundCueTemplateNodeParams& Params, USoundClass* SoundClass) const
{
	USoundNodeSoundClass* SoundClassNode = ConstructNode<USoundNodeSoundClass>(SoundCue, Params);
	SoundClassNode->SoundClassOverride = SoundClass;
	return SoundClassNode;
}

USoundNode* UFortSoundCueTemplateBase::AddAttenuationNode(USoundCue& SoundCue, FFortSoundCueTemplateNodeParams& Params, USoundAttenuation* Attenuation) const
{
	USoundNodeAttenuation* AttenuationNode = ConstructNode<USoundNodeAttenuation>(SoundCue, Params);
	AttenuationNode->AttenuationSettings = Attenuation;
	return AttenuationNode;
}

USoundNode* UFortSoundCueTemplateBase::AddLicensedContentSwitcherNode(USoundCue& SoundCue, FFortSoundCueTemplateNodeParams& Params, bool bLooping, bool bLinkMuteOthersPin) const
{
	if (!TemplateDefaults)
	{
		return nullptr;
	}

	UFortSoundNodeLicensedContentSwitcher* SwitcherNode = ConstructNode<UFortSoundNodeLicensedContentSwitcher>(SoundCue, Params);

	USoundNodeWavePlayer* LicensedWavePlayer = nullptr;
	if (bLooping)
	{
		Params.bSetAsParent = false;
		LicensedWavePlayer = ConstructNode<USoundNodeWavePlayer>(SoundCue, Params);
		LicensedWavePlayer->SetSoundWave(TemplateDefaults->LicensedTrackAlternative);
		LicensedWavePlayer->bLooping = true;
	}
	else
	{
		SwitcherNode->InsertChildNode(0);
	}

	++Params.Row;
	SwitcherNode->InsertChildNode(1);

	if (TemplateDefaults->LicensedSubmix)
	{
		SoundCue.bEnableBaseSubmix = true;
		SoundCue.SoundSubmixObject = TemplateDefaults->LicensedSubmix;
	}

	static const FName MuteOthersPinName(TEXT("Mute Others"));
	if (bLinkMuteOthersPin)
	{
		if (bLooping && LicensedWavePlayer)
		{
			UEdGraphPin* OutputPin = CastChecked<USoundCueGraphNode_Base>(LicensedWavePlayer->GetGraphNode())->GetOutputPin();
			UEdGraphPin* InputPin = SwitcherNode->GetGraphNode()->FindPin(MuteOthersPinName, EGPD_Input);
			if (OutputPin && InputPin)
			{
				SwitcherNode->ChildNodes[1] = LicensedWavePlayer;
				InputPin->MakeLinkTo(OutputPin);
			}
		}
	}
	else
	{
		Params.PendingPinLinks.Add({ 1, MuteOthersPinName });
	}

	return SwitcherNode;
}

void UFortSoundCueTemplateBase::AddChildNode(USoundCue& SoundCue, USoundNode* ParentNode, USoundNode* ChildNode, int32 InputPinIndex) const
{
	if (ParentNode && ChildNode)
	{
		AddSoundNodeChild(*ParentNode, *ChildNode, InputPinIndex);
	}
}

void UFortSoundCueTemplateBase::AddWavePlayerNodes(USoundCue& SoundCue, const FFortSoundCueTemplateNodeParams& Params, const TArray<USoundWave*>& Waves, bool bLooping, bool bAllowBranchCulling) const
{
	FFortSoundCueTemplateNodeParams WaveParams = Params;
	int32 NodePosY = static_cast<int32>(GetInitialHeightOffset() + GetNodeHeightOffset() * Params.Row);

	USoundNodeRandom* RandomNode = ConstructNode<USoundNodeRandom>(SoundCue, WaveParams);
	RandomNode->bShouldExcludeFromBranchCulling = !bAllowBranchCulling;

	WaveParams.InputPinIndex = 0;
	WaveParams.bSetAsParent = false;

	for (USoundWave* Wave : Waves)
	{
		if (Wave)
		{
			USoundNodeWavePlayer* WavePlayer = ConstructNode<USoundNodeWavePlayer>(SoundCue, WaveParams);
			WavePlayer->GraphNode->NodePosY = NodePosY;
			NodePosY += 50;
			WavePlayer->SetSoundWave(Wave);
			WavePlayer->bLooping = bLooping;
			++WaveParams.InputPinIndex;
		}
	}
}

void UFortSoundCueTemplateBase::Preview()
{
	PreviewComponent = GEditor->ResetPreviewAudioComponent();
	if (PreviewComponent)
	{
		PreviewComponent->Sound = this;
		PreviewComponent->bAutoDestroy = false;
		PreviewComponent->bIsUISound = true;
		PreviewComponent->bAllowSpatialization = false;
		PreviewComponent->bReverb = false;
		PreviewComponent->bCenterChannelOnly = false;
		PreviewComponent->bIsPreviewSound = true;
		UpdatePreviewParameters();
		PreviewComponent->Play();
	}
}

void UFortSoundCueTemplateBase::ReloadDefaultSettings()
{
	DefaultTemplateSettings = nullptr;
	LoadTemplateDefaultSettings();
}

void UFortSoundCueTemplateBase::StopPreview()
{
	if (PreviewComponent)
	{
		PreviewComponent->Stop();
	}
}

bool UFortSoundCueTemplateBase::GetPreviewParameters(TArray<FAudioParameter>& OutParameters) const
{
	return false;
}

void UFortSoundCueTemplateBase::ValidateTemplateData()
{
	StartDelay = FVector2D(FMath::Min(StartDelay.X, StartDelay.Y), FMath::Max(StartDelay.X, StartDelay.Y));
	PitchModulationRange = FVector2D(FMath::Min(PitchModulationRange.X, PitchModulationRange.Y), FMath::Max(PitchModulationRange.X, PitchModulationRange.Y));
	VolumeModulationRange = FVector2D(FMath::Min(VolumeModulationRange.X, VolumeModulationRange.Y), FMath::Max(VolumeModulationRange.X, VolumeModulationRange.Y));
}

void UFortSoundCueTemplateBase::LinkPendingPinLinks(USoundNode& Node, FFortSoundCueTemplateNodeParams& Params)
{
	if (Params.ParentNode && Params.PendingPinLinks.Num() > 0)
	{
		UEdGraphPin* OutputPin = CastChecked<USoundCueGraphNode_Base>(Node.GetGraphNode())->GetOutputPin();
		if (UEdGraphNode* ParentGraphNode = Params.ParentNode->GetGraphNode())
		{
			for (const FFortSoundCueTemplatePendingPinLink& PendingPinLink : Params.PendingPinLinks)
			{
				UEdGraphPin* InputPin = ParentGraphNode->FindPin(PendingPinLink.PinName, EGPD_Input);
				if (InputPin && PendingPinLink.ChildIndex >= 0 && PendingPinLink.ChildIndex < Params.ParentNode->ChildNodes.Num())
				{
					Params.ParentNode->ChildNodes[PendingPinLink.ChildIndex] = &Node;
					InputPin->MakeLinkTo(OutputPin);
				}
			}
		}

		Params.PendingPinLinks.Reset();
	}
}

void UFortSoundCueTemplateBase::UpdatePreviewParameters()
{
	if (PreviewComponent)
	{
		TArray<FAudioParameter> PreviewParameters;
		if (GetPreviewParameters(PreviewParameters))
		{
			PreviewComponent->SetParameters(MoveTemp(PreviewParameters));
		}
	}
}

void UFortSoundCueTemplateBase::UpdateSoundCueTemplateClass()
{
	SoundCueTemplateClass = FAssetData(this).GetClass();
}

void UFortSoundCueTemplateBase::UpdateTemplateDefaults()
{
	if (SoundCueTemplateClass)
	{
		if (const UFortSoundCueTemplateSettings* TemplateSettings = GetDefault<UFortSoundCueTemplateSettings>())
		{
			TemplateDefaults = TemplateSettings->GetDefaultSettingsForTemplateType(SoundCueTemplateClass.Get());
			if (!DefaultTemplateSettings)
			{
				DefaultTemplateSettings = DuplicateObject<UFortSoundCueTemplateDefaults>(TemplateDefaults, this);
			}
		}
	}
}
#endif
